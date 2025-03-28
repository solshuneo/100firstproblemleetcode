/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array}
 */
var chunk = function(arr, size) {
    let subquence = []
    let ans = []
    for (let i = 0; i < arr.length; ++i) {
        subquence.push(arr[i]);
        if (i == arr.length - 1 || (i + 1) % size == 0) {
            ans.push(subquence);
            subquence = [];
        }
    }
    return ans;
};
