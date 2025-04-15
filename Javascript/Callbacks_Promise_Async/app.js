
// console.log('First');
// console.log('Second');


// setTimeout(function(){
//     console.log('Three');
// },1000)
// console.log('Fourth')




// CallBack Hell

function getData(dataId, nextData){
    //2s 
    setTimeout(()=>{
        console.log('Data',dataId);
        if(nextData){
            nextData();
        }
    },2000);
}

getData(1, ()=>{
    getData(2,()=>{
        getData(3,()=>{
            getData(9)
        });
    });
})





//Promises

// let promise = new Promise((resolve,reject)=>{
//     console.log('I am a Promise');
//    resolve('Success');
// })

// function getData(dataId, nextData){
//     return new Promise((resolve,reject)=>{
//         setTimeout(()=>{
//             console.log('Data: ',dataId);
//             resolve('Success');
//             if(nextData){
//                 nextData();
//             }
//         },10000)
//     })
// }