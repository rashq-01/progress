import { useState } from "react";
import "./SearchBar.css";

function SearchBar({onSearch,placeHolder = "Search posts.."}){
    const [searchTerm,setSearchTerm] = useState('');

    const handleInputChange=(e)=>{
        const value = e.target.value;
        setSearchTerm(value);
        onSearch(value);  // Real-time Search
    };

    const handleClear = ()=>{
        searchTerm("");
        onSearch("");
    };

    const handleKeyPress = (e)=>{
        if(e.key==="Enter"){
            console.log("Searching for : ",searchTerm);
            e.target.blur();
        }
    }

    return (
        <div className="search-bar">
            <span className="search-icon">🔍</span>
            <input type="text"
                    value={searchTerm}
                    onChange={handleInputChange}
                    onKeyDown={handleKeyPress}
                    placeholder={placeHolder} />
                    {searchTerm && (
                        <button className="clear-btn"
                                onClick={handleClear}
                                onMouseEnter={()=>console.log(`Clear button hovered`)}>
                            X
                        </button>
                    )}
        </div>
    );
}

export default SearchBar;