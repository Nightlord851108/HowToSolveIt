class Circle extends Shape{
    constructor(v, r){
        super(v, r);
        this.name = 'Circle';
    }
    description(){
        var s = '{' + this.name + ';';
        s += '(' + this.o.component()[0].toString() + ',' + this.o.component()[1].toString() + ');';
        s += this.r.toString() + '}';
        return s;
    }
}

function createCircle(s) {
    s = s.split(';');
    if (s[0].charAt(0) != '(' || s[0].charAt(s[0].length - 1) != ')')
        throw new Error('Format Error')
    s[0] = s[0].substring(1, s[0].length-1);
    var v = [parseInt(s[0].split(',')[0]), parseInt(s[0].split(',')[1])];
    var r = parseInt(s[1]);
    return new Circle(new Vector(v), r);
}
