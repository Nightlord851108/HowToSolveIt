describe('Test ConvexPolygon', function(){
    it('constructor', function(){
        var v = [
            new Vector([0,0]),
            new Vector([1,1]),
            new Vector([0,1])
        ]
        var cp = new ConvexPolygon(v);
        expect('{ConvexPolygon;(0,0)/(1,1)/(0,1)}').toEqual(cp.description());
    });
});
