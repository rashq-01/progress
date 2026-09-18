const Home = require('../model/home');

exports.getAddHome = (req, res, next) => {
    res.render('addHome', {pageTitle: 'Add Home to airbnb', currentPage: 'addHome',
    });
  };


  exports.postAddhome = (req, res, next) => {
    const house = new Home(req.body.houseName, req.body.price, req.body.location, req.body.rating, req.body.photoUrl);
    house.save();
    res.render('homeAdded', {pageTitle: 'Home Added Successfully', currentPage: 'homeAdded'});
  }

  //User Router
  exports.getHome = (req, res, next) => {
    Home.fetchAll((registeredHomes) => {
        res.render('home', { registeredHomes: registeredHomes, pageTitle: 'Airbnb Home', currentPage: 'Home' });
    });
};



  //404 Error
  exports.error = (req, res, next) => {
    res.status(404).render('404', {pageTitle: 'Page Not Found', currentPage: '404'});
  }