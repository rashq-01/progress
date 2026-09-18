//Moudles
const path = require('path');
const model = require('../model/home');




exports.getHome = (req,res,next)=>{
    console.log(req.url);
    res.render('home');

};

exports.getBookManagement = (req,res,next)=>{
    console.log(req.url);
    res.render('book-management');

};
exports.postBookManagement = (req,res,next)=>{
    console.log(req.body.title, req.body.author, req.body.isbn, req.body.genre);
    const bookCopy = new model.bookClass(req.body.title, req.body.author, req.body.isbn, req.body.genre);
    bookCopy.save();
    res.render('bookAdded');
}
exports.postUserManagement = (req,res,next)=>{
    console.log(req.body.username, req.body.email);
    const userCopy = new model.userClass(req.body.username, req.body.email, req.body.password);
    userCopy.save();
    res.render('userAdded');
}

exports.getUserManagement = (req,res,next)=>{
    console.log(req.url);
    res.render('user-management');

};
exports.getAlluser = (req,res,next)=>{
    model.userClass.fetchUser((users)=>{
        res.render('userData',{allusers: users});
    });
    

};
exports.getAllBook = (req,res,next)=>{
    model.bookClass.fetchBook((book)=>{
    res.render('bookData',{allbooks: book});
    });

};