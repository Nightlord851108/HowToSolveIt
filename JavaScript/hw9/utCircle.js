describe('Test Circle', function(){
    it('Constructor', function(){
        var c = new Circle(new Vector([0, 0]), 1);
        expect(c.description()).toEqual('{Circle;(0,0);1}');
    });
    it('Exception', function(){
        var error = function(){
            new Circle(new Vector([1,1,1]), 2);
        }
        expect(error).toThrow(Error('Dimension Error'));
    });
});

describe ('Create Circl', function() {
    it('Normal', function() {
        var s = '(0,0);2';
        expect(createCircle(s).description()).toEqual('{Circle;(0,0);2}');
    });
    it('Exception format error', function() {
        var s = '0,0);2';
        var error = function (){
            createCircle(s);
        }
        expect(error).toThrow(Error('Format Error'));
    });
});
