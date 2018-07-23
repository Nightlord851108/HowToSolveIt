describe('get ConvexPolygon from string', function() {
    it ('Normal', function() {
        var s = '{convex polygon;(0,0)/(3,0)/(3,4)}';
        expect(getShapeFromString(s).description()).toEqual('{ConvexPolygon;(0,0)/(3,0)/(3,4)}')
    });
    it('Exception Not a shape', function(){
        var s = '{onvex polygon;(0,0)/(3,0)/(3,4)}';
        var error = function(){
            getShapeFromString(s);
        };
        expect(error).toThrow(Error('Not a shape'));
    });
    it('Exception Format Error', function(){
        var s = 'convex polygon;(0,0)/(3,0)/(3,4)}';
        var error = function(){
            getShapeFromString(s);
        };
        expect(error).toThrow(Error('Format Error'));
    });
});

describe('Get Circle from string', function() {
    it ('Normal', function() {
        var s = '{circle;(0,0);1}';
        expect(getShapeFromString(s).description()).toEqual('{Circle;(0,0);1}')
    })
    it ('Exception', function() {
        var s = '{; (0,0); 1}'
        var error = function() {
            getShapeFromString(s);
        }
        expect(error).toThrow(Error('Not a shape'));
    })

})
