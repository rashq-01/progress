//Modules
const fs = require('fs');
const path = require('path');
const rootDir = require('../utils/pathUtil');

module.exports = class Home{
    constructor(houseName, price, location, rating, photoUrl){
        this.houseName = houseName;
        this.price = price;
        this.location = location;
        this.rating = rating;
        this.photoUrl = photoUrl;
    }

    save(){
        Home.fetchAll((registeredHomes) => {
            registeredHomes.push(this);
            const homeDataPath = path.join(rootDir,'data','home.json');

            fs.writeFile(homeDataPath, JSON.stringify(registeredHomes),error=>{
                console.log("File Writing Concluede",error);
            });
        });
    };
    
    static fetchAll(callback){
        const homeDataPath = path.join(rootDir,'data','home.json');
        fs.readFile(homeDataPath, (err,data)=>{
            console.log('File read',err,data);
            if(!err){
                callback(JSON.parse(data));
            }
            else{
            callback([]);
            }
        });

        
    };
};