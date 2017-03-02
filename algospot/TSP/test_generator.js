// set input
var n = 8;
var maxDistance = 1000;

var arr = new Array(n);
for (var i=0; i<n; i++) {
    arr[i] = new Array(n);
}
for (var i=0; i<n; i++) {
    for (var j=0; j<i; j++) {
        arr[i][j] = arr[j][i];
    }
    arr[i][i] = 0;
    for (var j=i+1; j<n; j++) {
        arr[i][j] = Math.random()*maxDistance;
    }
}
var str = "\n1 " + n + "\n";
for (var i=0; i<n; i++) {
    for (var j=0; j<n; j++) {
        str += " " + arr[i][j];
    }
    str += "\n";
}
str += "\n";
console.log(str);
