describe('find', function() {
    it('Check -7', function() {
        var a = [-3, 9, 3, 0, 5, -7, 3, 6, -6, 1];
        expect(a.includes(-7)).toEqual(true);
    });
});

describe('square', function() {
    it('Normal', function() {
        var x = 2;
        expect(square(x)).toEqual(4);
    });
    it ('For_each', function() {
        var a = [-3, 9, 3, 0,5, -7, 3, 6, -6, 1];
        expect(square(a)).toEqual([9, 81, 9, 0, 25, 49, 9, 36, 36, 1]);
    });
});

describe ('isPositive', function() {
    it ('positive', function() {
        var a = 1;
        expect(isPositive(a)).toEqual(true);
    });
    it ('Negative', function() {
        expect(isPositive(-1)).toEqual(false);
    });
});

describe ('find all', function() {
    it ('Normal', function() {
        var a = [-3, 9, 3, 0, 5, -7, 3, 6, -6, 1];
        expect(findAll(a, 10, 0, isPositive)).toEqual([9, 3, 0, 5, 3, 6, 1])
    });
    it ('Exception', function() {
        var a = [1, 2, 3];
        var error = function () {
            findAll(a, 3, 0, 3);
        };
        expect(error).toThrow(Error('Not a function!'))
    });
});
