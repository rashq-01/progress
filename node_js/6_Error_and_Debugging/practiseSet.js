function calculateArea(width, height){
    return (height*height);
};

let width = 10, height = 5;
let area = calculateArea(width,height);
if(area > 100){
    console.log('Area is Large');
}
else{
    console.log('The area is small');
}

if(width * height > 100){
    console.log('Area is greater than or equal to 100')
}