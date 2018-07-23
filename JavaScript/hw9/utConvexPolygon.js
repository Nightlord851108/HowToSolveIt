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
    it('Exception', function(){
        var v = [
            new Vector([0,0]),
            new Vector([1,2,3]),
            new Vector([1,1])
        ];
        var error = function(){
            new ConvexPolygon(v);
        };
        expect(error).toThrow(Error('Dimension Error'));
    });
});

describe('area', function() {
    it ('normal', function(){
        var v = [
            new Vector([0,0]),
            new Vector([1,0]),
            new Vector([1,1]),
            new Vector([0,1])
        ];
        var cp = new ConvexPolygon(v);
        expect(cp.area()).toEqual(1);
    });
});

describe ('perimeter', function() {
    it ('Normal', function() {
        var v = [
            new Vector([0, 0]),
            new Vector([1, 0]),
            new Vector([1, 1]),
            new Vector([0, 1])
        ];
        var cp = new ConvexPolygon(v);
        expect(cp.perimeter()).toEqual(4);
    });
});

describe('createConvexPolygon', function(){
    it('normal', function(){
        var  s = '(0,0)/(0,1)/(1,1)/(1,0)';
        expect(createConvexPolygon(s).description()).toEqual('{ConvexPolygon;(0,0)/(1,0)/(1,1)/(0,1)}');
    });
    it ('Exception', function() {
        var s = '0,0/(0,1)/(1,1)/(1,0)';
        var error = function(){
            createConvexPolygon(s);
        };
        expect(error).toThrow(Error('Format Error'))
    });

});
