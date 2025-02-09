exports.getAddHome = (req, res, next) => {
    res.render('addHome', {pageTitle: 'Add Home to airbnb', currentPage: 'addHome',
    });
  };