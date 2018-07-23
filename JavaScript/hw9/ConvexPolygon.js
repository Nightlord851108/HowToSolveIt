class ConvexPolygon extends Shape{
    constructor(v){
        super(v);
        this.name = 'ConvexPolygon';
    }
    description(){
        var s = '{' + this.name + ';'
        for(var i = 0; i < this.n; i++){
            s += '(' + this.vertices[i].component({'index':1}).toString();
            s += ',' + this.vertices[i].component({'index':2}).toString();
            s += ')/';
        }
        return s.substring(0,s.length - 1) + '}';
    }
    area(){
        var sum = 0;
        var v = this.vertices;
        for (var i = 0; i < this.n - 1; i++)
            sum += v[i].component()[0] * v[i+1].component()[1] - v[i].component()[1] * v[i+1].component()[0];
        return Math.abs(sum)/2;
    }
    perimeter() {
        var p = 0;
        for (var i = 0; i < this.n-1; i++) {
            p += Vector.sub(this.vertices[i], this.vertices[i+1]).length();
        }
        p += Vector.sub(this.vertices[0], this.vertices[this.n-1]).length();
        return p;
    }
}

function createConvexPolygon(s, separator = '/'){
    s = s.split(separator);
    var v = []
    for(var i in s){
        if(s[i].charAt(0) != '(' || s[i].charAt(s[i].length - 1) != ')')
            throw new Error('Format Error');
        s[i] = s[i].substring(1,s[i].length - 1);
        s[i] = s[i].split(',');
        v.push( new Vector( [ parseInt(s[i][0]), parseInt(s[i][1]) ] ) );
    }
    sortVector(v);
    return new ConvexPolygon(v);
}

//           ffffffff
//          fffffffff
//         ffff
//         ffff
//         ffff
// ffffffffffffffffffff     uuu         uuu
// ffffffffffffffffffff     uuu         uuu
//         ffff             uuu         uuu
//         ffff             uuu         uuu
//         ffff              uuu       uuuuu
//         ffff               uuu     uuu uu
//         ffff                 uuuuuuu    uuu
