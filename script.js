// Wait until the DOM content is fully loaded
document.addEventListener('DOMContentLoaded', function () {
    const navLinks = document.querySelectorAll('.nav-link');
    const progressBar = document.getElementById('myProgressBar');                                                     // Get the progress bar element
    const menuToggle = document.querySelector('.menu-toggle input');
    const menu = document.querySelector('.menu');
    const toggleBtns = document.querySelectorAll('.toggle-btn');
    const collapsibles = document.querySelectorAll('.collapsible');
    const collapseAllBtn = document.getElementById('collapse-all-btn');
    var counter = 0;
    const scrollContainer = document.querySelector('.scroll-container');
    let idleTimeout;

    // Collapse the search bar when clicking outside the container
    document.addEventListener('click', (event) => {
        if (!searchContainer.contains(event.target)) {
            collapseSearch();
        }
    });

    function showScrollbars() {
        console.log('Show scrollbars');
        scrollContainer.classList.remove('hide-scrollbars');
        resetIdleTimer();
    }

    function hideScrollbars() {
        console.log('Hide scrollbars');
        scrollContainer.classList.add('hide-scrollbars');
    }

    function resetIdleTimer() {
        clearTimeout(idleTimeout);
        idleTimeout = setTimeout(hideScrollbars, 2000); // Hide after 2 seconds of inactivity
    }

    // Show scrollbars on user activity
    ['mousemove', 'keydown', 'scroll'].forEach(event => {
        document.addEventListener(event, showScrollbars);
    });

    resetIdleTimer();       // Initially hide scrollbars

    menuToggle.addEventListener('change', (event) => {
        menu.style.display = menu.style.display === 'block' ? 'none' : 'block';
        event.stopPropagation(); // Prevent click from propagating to the body
    });

    // Close dropdown when clicking outside
    document.body.addEventListener('click', () => {
        if (menu.style.display === 'block') {
            menu.style.display = 'none';
        }
    });

    function goToNewPage(page) {
        window.location.href = page;
        counter = 0;                        // Reset counter on page load
    }

    function handleNavigationClick(event, page) {
        event.preventDefault();
        goToNewPage(page);
    }

    function updateProgressBar() {                                                                                  // Function to update the progress bar
        var scrollTop = document.documentElement.scrollTop || document.body.scrollTop;                              // Get the current scroll position
        var scrollHeight = document.documentElement.scrollHeight - document.documentElement.clientHeight;           // Get the total height of the page
        var scrolled = (scrollTop / scrollHeight) * 100;                                                            // Calculate the percentage scrolled
        progressBar.style.width = scrolled + "%";                                                                   // Update the width of the progress bar
    }

    navLinks.forEach(function (link) {
        link.addEventListener('click', function (event) {
            const page = link.getAttribute('data-page');
            handleNavigationClick(event, page);
        });
    });

    toggleBtns.forEach((button, index) => {
        button.addEventListener('click', () => {
            const collapsible = collapsibles[index];

            if (collapsible.style.maxHeight && collapsible.style.maxHeight !== "0px") {
                collapsible.style.maxHeight = "0px"; // Collapse
            } else {
                collapsible.style.maxHeight = collapsible.scrollHeight + "px"; // Expand
            }
        });
    });

    if (collapseAllBtn) {
        collapseAllBtn.addEventListener('click', () => {
            const isCollapsing = collapseAllBtn.textContent === 'Collapse All';
            collapseAllBtn.textContent = isCollapsing ? 'Expand All' : 'Collapse All';

            collapsibles.forEach((collapsible) => {
                if (counter % 2 == 0) {                 //even
                    collapsible.style.maxHeight = "0px";
                }
                else if (counter % 2 != 0) {            //odd
                    collapsible.style.maxHeight = collapsible.scrollHeight + "px";
                }
                else if (counter == 0) {                //1st iteration
                    collapsible.style.maxHeight = "0px";
                }
            });
            counter += 1;
        });
    }

    window.onscroll = function () {
        console.log('Scroll event triggered'); // Check if this logs
        const progressBar = document.getElementById('myProgressBar');
        if (progressBar) {
            const scrollTop = document.documentElement.scrollTop || document.body.scrollTop;
            const scrollHeight = document.documentElement.scrollHeight - document.documentElement.clientHeight;
            const progress = (scrollTop / scrollHeight) * 100;
            progressBar.style.width = progress + '%';
        } else {
            console.error('Progress bar not found on this page.');
        }
        updateProgressBar();
    };

    updateProgressBar();                                                                                            // Update the progress bar on page load
});

function goHome() {
    window.location.href = "home.html"; // Redirect to home page
}
