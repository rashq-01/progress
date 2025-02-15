const Home = require("../models/home");
const Favourite = require('../models/favourites');

exports.getIndex = (req, res, next) => {
  Home.fetchAll((registeredHomes) =>
    res.render("store/index", {
      registeredHomes: registeredHomes,
      pageTitle: "airbnb Home",
      currentPage: "index",
    })
  );
};

exports.getHomes = (req, res, next) => {
  Home.fetchAll((registeredHomes) =>
    res.render("store/home-list", {
      registeredHomes: registeredHomes,
      pageTitle: "Homes List",
      currentPage: "Home",
    })
  );
};

exports.getBookings = (req, res, next) => {
  res.render("store/bookings", {
    pageTitle: "My Bookings",
    currentPage: "bookings",
  })
};

exports.getFavouriteList = (req, res, next) => {
  Favourite.getFavourites((favourites)=>{
    Home.fetchAll((registeredHomes) => {
      const favouriteHomes = registeredHomes.filter(home =>{
        return favourites.includes(home.id);
      });
      res.render("store/favourite-list", {
        favouriteHomes: favouriteHomes,
        pageTitle: "My Favourites",
        currentPage: "favourites",
      })
    },next);

  },next)
};

exports.postAddToFavourite = (req,res,next)=>{
  Favourite.addToFavourite(req.body.id,error=>{
    if(error){
      console.log('Error while marking favourites',error)
    }
    res.redirect('/favourites');
  })
}



exports.getHomeDetails = (req,res,next)=>{
  const homeId = req.params.homeId;
  console.log('At home detail',homeId);
  Home.findById(homeId,(home)=>{
    if(!home){
      console.log("Homes not found");
      res.redirect('/homes');
    }
    else{
      console.log('Home details Found',home);
      res.render('store/home-detail',{
        pageTitle: "Home Detail",
        currentPage: "Home",
        home: home,
      });
    };
  });
};