const Home = require("../models/home");
const Favourite = require('../models/favourites');

exports.getIndex = (req, res, next) => {
  Home.find().then((registeredHomes) => {
    res.render("store/index", {
      registeredHomes: registeredHomes,
      pageTitle: "airbnb Home",
      currentPage: "index",
    })

  })
  
};

exports.getHomes = (req, res, next) => {
  Home.find().then((registeredHomes) => {
    res.render("store/home-list", {
      registeredHomes: registeredHomes,
      pageTitle: "Homes List",
      currentPage: "Home",
    })
  });
};

exports.getBookings = (req, res, next) => {
  res.render("store/bookings", {
    pageTitle: "My Bookings",
    currentPage: "bookings",
  })
};

exports.getFavouriteList = (req, res, next) => {
  Favourite.find()
  .populate('houseId')
  .then((favourites)=>{
    const favouriteHomes = favourites.map((fav) => fav.houseId);
      res.render("store/favourite-list", {
        favouriteHomes: favouriteHomes,
        pageTitle: "My Favourites",
        currentPage: "favourites",
      });
    });
};


exports.postAddToFavourite = (req,res,next)=>{
  const homeId = req.body.id;
  Favourite.findOne({houseId: homeId}).then((fav)=>{
  if(fav){
    console.log("Already marked as favourite");
  }
  else{
    fav = new Favourite({houseId: homeId});
    fav.save().then((result)=>{
      console.log("Fav added: ",result);
    });
  }
  res.redirect("/favourites");
}).catch((err)=>{
  console.log("Error while marking favourite: ",err);
});
};

exports.postRemoveFavourite = (req,res,next)=>{
  const homeId = req.params.homeId;
  Favourite.findOneAndDelete({houseId: homeId}).then((result)=>{
    console.log('Fav removed: ',result);
  }).catch((error)=>{
    console.log('Error while removing: ',error);
  }).finally(()=>{
    res.redirect('/favourites');
  })
}



exports.getHomeDetails = (req,res,next)=>{
  const homeId = req.params.homeId;
  Home.findById(homeId).then((home) => {
    if(!home){
      console.log("Homes not found");
      res.redirect('/homes');
    }
    else{
      res.render('store/home-detail',{
        pageTitle: "Home Detail",
        currentPage: "Home",
        home: home,
      });
    };
  });
};