class ConvexPolygon{
    constructor(v){
        this.n = v.length;
        this.vertices = v;
    }
    description(){
        var s = '{ConvexPolygon;'
        for(var i = 0; i < this.n; i++){
            s += '(' + this.vertices[i].component({'index':1}).toString();
            s += ',' + this.vertices[i].component({'index':2}).toString();
            s += ')/';
        }
        return s.substring(0,s.length - 1) + '}';
    }
}
