// Find forms on the page
const formEl = document.getElementById("apiform")
formEl.addEventListener('submit', submitRequest);

// Find the box alert
const alertEl = document.getElementById("boxalert");

function submitRequest(e) {
    e.preventDefault();
    $("#boxalert").show();
    alertEl.style['display'] = 'block';
    formEl.style.cssText = 'filter: blur(8px); -webkit-filter: blur(8px);'
    const formData = new FormData(formEl);
    const url = "https://rapihs.dhruvtuteja.tech/heart_stroke?";

    fetch(url + new URLSearchParams(formData), {

        method: "GET",

        // })
    }).then(
        response => response.json().then(function (text) {
            // do something with the text response 
            console.log(text)
            if (text[0] === "[1]") {
                document.getElementById("boxtext").innerHTML = "Patient will get stroke";
            }
            else
                document.getElementById("boxtext").innerHTML = "Patient will not get stroke";
        })
    )
}

document.getElementById("myBtn").addEventListener("click", function () {
    formEl.style.cssText = ""
});