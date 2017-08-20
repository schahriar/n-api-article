const addon = require('./build/Release/module');
const value = 8;    
console.log(`${value} times 2 equals`, addon.my_function(value));