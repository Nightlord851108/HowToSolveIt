// const main = require('main')

describe('TestAdd', function(){
    it("Normal", function() {
        expect(3).toEqual(add1(1, 2));
    });
    it('Negative', function(){
        expect(-3).toEqual(add1(-1, -2))
    })
});

describe('TestSub', function(){
    it('Normal', function(){
        expect(1).toEqual(sub(2, 1));
    });
});

describe('TestMul', function(){
    it('Normal', function(){
        expect(2).toEqual(mul(1, 2));
    });
});

describe('TestMaxNum', function(){
    it('Normal', function(){
        expect(2).toEqual(maxNum(1, 2));
    });
});
