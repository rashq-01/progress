const mongoose = require('mongoose');
const favourites = require('./favourites');


const homeSchema = mongoose.Schema({
  houseName: {
    type: String,
    required: true
  },
  price: {
    type: Number,
    required: true
  },
  location: {
    type: String,
    required: true
  },
  rating: {
    type: Number,
    required: true
  },
  photoUrl: String,
  description: String,

});

homeSchema.pre('findOneAndDelete', async function(next){
  console.log("Came to pre hook while deleting a home");
  const homeId = this.getQuery()._id;
  await favourites.deleteMany({houseId: homeId});
  next();
})

module.exports = mongoose.model("Home", homeSchema);





/*

  save()
  find(homeId)
  deleteById(homeId)


*/


