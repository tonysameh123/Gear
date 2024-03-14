window.addEventListener('scroll', function() {
    var backToTopButton = document.getElementById('backToTopButton');
    if (window.scrollY > 300) {
    backToTopButton.classList.add('show');
    } else {
    backToTopButton.classList.remove('show');
    }
});
