Array.prototype.shuffle = function() {
      var tmp, rand;
      for(var i =0; i < this.length; i++){
              rand = Math.floor(Math.random() * this.length);
              tmp = this[i];
              this[i] = this[rand];
              this[rand] = tmp;
            }
}

var generate = function (n, m, ratio) {
    var names = [];
    for (var i=0; i<n; ++i) names.push("name"+i);

    str = "\n1\n" + n + " " + m + "\n";
     for (var i=0; i<n; ++i) str += names[i] + " ";
    str += "\n"
    for (var i=0; i<m; ++i) {
            var numOfFriends = Math.round(Math.random()*(n/ratio))+1;
            str += numOfFriends;
            names.shuffle();
            for (var j=0; j<numOfFriends; ++j)
                    str += " " + names[j];
            str += "\n"
    }
    str += "\n";
    return str;
}
var n = 20;
var m = 25;
generate(n,m,3);

