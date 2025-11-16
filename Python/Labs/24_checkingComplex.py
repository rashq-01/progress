import json as js

# Example of json
json_str = '{"name":"Ravi","age":21,"subjects":["math","Physics"],"address":{"city":"Hyderabad"}}'

# Parse JSON String
data = js.loads(json_str)

# Function to check for complex objects
def containsComplex(obj):
    if isinstance(obj,dict):
        for value in obj.values():
            if isinstance(value,(dict,list)):
                return True
    elif isinstance(obj,list):
        for item in obj:
            if isinstance(item,(dict,list)):
                return True
    return False


# Check and display result
if containsComplex(data):
    print("The JSON string contains a complex object")
else:
    print("The JSON string does not contain any complex object")
