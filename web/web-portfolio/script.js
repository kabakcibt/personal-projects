const words = ["web geliştiriciyim.", "büyük veri analistiyim.", "Programlamacıyım.", "Veri altyapısını soruglarım."];
let wordIndex = 0;
let charIndex = 0;
let isDeleting = false;
const typingText = document.getElementById("typing-text");

function type() {
    const currentWord = words[wordIndex];

    if (isDeleting) {
        // Harf silme modu
        typingText.textContent = currentWord.substring(0, charIndex - 1);
        charIndex--;
    } else {
        // Harf yazma modu
        typingText.textContent = currentWord.substring(0, charIndex + 1);
        charIndex++;
    }

    // Hız ayarları: Silerken daha hızlı olsun
    let typeSpeed = isDeleting ? 50 : 100;

    // Kelime tamamen bittiyse
    if (!isDeleting && charIndex === currentWord.length) {
        typeSpeed = 1500; // Kelime bittiğinde 1.5 saniye bekle
        isDeleting = true;
    } else if (isDeleting && charIndex === 0) {
        isDeleting = false;
        wordIndex = (wordIndex + 1) % words.length; // Bir sonraki kelimeye geç (döngüsel)
        typeSpeed = 500; // Yeni kelimeye geçmeden önce yarım saniye bekle
    }

    setTimeout(type, typeSpeed);
}

// Sayfa yüklendiğinde efekti başlat
document.addEventListener("DOMContentLoaded", type);