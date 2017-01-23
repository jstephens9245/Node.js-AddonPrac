const addon = require('../addon/build/Release/rightRotation');
// const reader = require('../addon/build/Release/imgReader');
// const PNG = require('png-js');

console.log(addon.add(1,3));
console.log(addon.rightRotation([1,2,3,4]));

let img = 'http://media.idownloadblog.com/wp-content/uploads/2014/09/Google-Chrome-37.0.2062.60-for-iOS-app-icon-small.png'

// PNG.decode(img, function(pixels) {
//   console.log(pixels);
//     // pixels is a 1d array (in rgba order) of decoded pixel data
// });
