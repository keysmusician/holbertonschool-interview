#!/usr/bin/node

const request = require('request');
const filmID = process.argv[2];
const baseURL = 'https://swapi-api.hbtn.io/api/';

request.get(baseURL + 'films/' + filmID,
  (error, response, body) => {
    if (error) {
      console.log(error);
    } else if (response.statusCode === 200) {
      const characterURLS = JSON.parse(body).characters;
      const characterNames = [];
      for (const characterURL of characterURLS) {
        characterNames.push(printCharacter(characterURL));
      }
      Promise.all(characterNames).then((names) => {
        for (const name of names) {
          console.log(name);
        }
      });
    }
  }
);

function printCharacter (url) {
  return new Promise((resolve, reject) => {
    if (!url) {
      reject(new Error('bad or missing response'));
    } else {
      request.get(url, (error, response, body) => {
        if (!error) {
          resolve(JSON.parse(body).name);
        }
      });
    }
  });
}
