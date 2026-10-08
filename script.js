let queue = [];

function addPatient() {
    let id = document.getElementById("id").value;
    let name = document.getElementById("name").value;
    let age = document.getElementById("age").value;
    let problem = document.getElementById("problem").value;

    if (id === "" || name === "" || age === "" || problem === "") {
        alert("Please fill all details!");
        return;
    }

    queue.push({
        id: id,
        name: name,
        age: age,
        problem: problem
    });

    displayPatients();

    document.getElementById("id").value = "";
    document.getElementById("name").value = "";
    document.getElementById("age").value = "";
    document.getElementById("problem").value = "";
}

function servePatient() {
    if (queue.length === 0) {
        alert("No patients waiting!");
        return;
    }

    let patient = queue.shift();

    alert("Serving Patient: " + patient.name);

    displayPatients();
}

function displayPatients() {
    let list = document.getElementById("patientList");
    let count = document.getElementById("count");

    count.innerText = queue.length;

    if (queue.length === 0) {
        list.innerHTML = "<p>No patients waiting.</p>";
        return;
    }

    list.innerHTML = "";

    queue.forEach(function(patient, index) {
        list.innerHTML += `
            <div class="patient">
                <b>Queue Position: ${index + 1}</b><br>
                ID: ${patient.id}<br>
                Name: ${patient.name}<br>
                Age: ${patient.age}<br>
                Problem: ${patient.problem}
            </div>
        `;
    });
}