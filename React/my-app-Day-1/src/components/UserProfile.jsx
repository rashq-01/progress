import './UserProfile.css'

function UserProfile(){
    const user = {
        name : "Rajesh Pandit",
        job : "Full-Stack Developer",
        bio : "Passionate about building beautiful web interface.",
        skills : ["React","Javascript","CSS","UI/UX"],
        email : "rashq122@gmail.com",
        phone : "+977 9809222012",
        isAvailable : true
    };

    return(
        <div className='profile-card'>
            <h1>User Profile</h1>
            <div className="profile-info">
                <p><strong>Name:</strong> {user.name}</p>
                <p><strong>Job:</strong> {user.job}</p>
                <p><strong>Bio:</strong> {user.bio}</p>
                <p><strong>Skills:</strong></p>
                <ul className='skill-list'>
                    {user.skills.map((skill, index) => (
                        <li key={index}>{skill}</li>
                    ))}
                </ul>
                <p><strong>Email:</strong> {user.email}</p>
                <p><strong>Phone:</strong> {user.phone}</p>
                <p><strong>Status:</strong> 
                    {user.isAvailable ? 
                        <span className='online-dot'>● Online</span> : 
                        " Not available"
                    }
                </p>
            </div>
        </div>
    )
}
export default UserProfile;