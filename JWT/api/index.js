const express = require('express');
const app = express();
app.use(express.json());

const users = [
    {
        id: "1",
        username: "john",
        password: "sjchoure",
        isAdmin: true
    },
    {
        id: "2",
        username: "jane",
        password: "okayokay",
        isAdmin: false
    }
];

app.post("/api/login", (req,res) => {
    const {username, password} = req.body;
    const user = users.find(u => {
        return u.username === username && u.password === password;
    });
    if(user) {
        res.json(user);
    } else {
        res.status(400).json("Username or Password Incorrect!");
    }
});

app.listen(5000, ()=> console.log("The server is started"));