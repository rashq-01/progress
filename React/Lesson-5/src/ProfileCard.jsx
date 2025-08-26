
function ProfileCard({Name,Age,Branch}){
    return(
        <div className="bg-gray-400 PfCard">
            <span className="SpanCard"><b><i>Profile Card</i></b></span>
            <br />
            <span>Your name is : <b>{Name}</b></span>
            <br />
            <span>Your age is : <b>{Age}</b></span>
            <br />
            <span>Your Branch is : <b>{Branch}</b></span>
            <br />
            <button className="bg-green-500 text-white px-4 py-2 rounded-lg hover:bg-gray-500 animate-pulse">Contact</button>
        </div>
    );
}



export default ProfileCard;