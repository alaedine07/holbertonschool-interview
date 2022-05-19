#!/usr/bin/node
const movie_id = process.argv[2];
const request = require('request');
const url = `https://swapi-api.hbtn.io/api/films/${movie_id}`;
request(url, async (err, response) => {
const data = JSON.parse(response.body);
chars_data = data.characters;
// console.log(chars_data);
chars_data.forEach(element => {
    // console.log(element);
    await new Promise((resolve, reject) => {
        request(element, function(err, response) {
        const char_data = JSON.parse(response.body);
        console.log(char_data["name"]);
        resolve();
    });
    });
});
});
