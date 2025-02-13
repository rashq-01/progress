//Modules
const path = require('path');
const fs = require('fs');
const rootDir = require('../utils/pathUtils');
const { error } = require('console');

exports.userClass = class userClass{
    constructor(username,email,password){
        this.username = username;
        this.email = email;
        this.password = password;
    }
    save(){
        exports.userClass.fetchUser((user)=>{
            user.push(this);
            const dataPath = path.join(rootDir,'data','user.json');
            fs.writeFile(dataPath,JSON.stringify(user),error=>{
                console.log('User details Writing Concluded',error);
            });

        });

    };

    static fetchUser(callback){
        const dataPath = path.join(rootDir,'data','user.json');
        fs.readFile(dataPath,(err,data)=>{
            console.log('userData Read: ',err,data);
            if(!err){
                callback(JSON.parse(data))
            }
            else{
                callback([]);
            }
        });
        
    };
};

exports.bookClass = class bookClass{
    constructor(title,author,isbn,genre){
        this.title = title;
        this.author = author;
        this.isbn = isbn;
        this.genre = genre;
    }
    save(){
        exports.bookClass.fetchBook((book)=>{
            book.push(this);
            const dataPath = path.join(rootDir,'data','book.json');
            fs.writeFile(dataPath,JSON.stringify(book),error=>{
                console.log('Book details writing concluded',error);
            });
        });

    };

    static fetchBook(callback){
        const dataPath = path.join(rootDir,'data','book.json');
        fs.readFile(dataPath,(err,data)=>{
            console.log('bookData Read: ',err,data);
            if(!err){
                callback(JSON.parse(data));
            }
            else{
                callback([]);
            }
        });
        
        
    };
};