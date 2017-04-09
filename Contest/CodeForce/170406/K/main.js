function main() {
    var n = readline(), str = readline();
    var res = "";
    for (var i=0; i<str.length; i++) {
        var c = str[i];
        if (c == "e" || c == "o") {
            var cnt = 0;

            while(i < str.length && str[i] == c) {cnt++; i++;}
            res += c;
            if (cnt == 2)
                res += c;
            i--;

        } else if (c == "a" || c == "i" || c == "u" || c == "y") {
            while(i < str.length && str[i] == c) { i++;}
            res += c;
            i--;

        } else {
            res += str[i];
        }
    }

    print(res);

}
main();
