function twoSum(nums: number[], target: number): number[] {
    const numMap = getNumberMap(nums);

    return target % 2 === 0 && numMap.get(target / 2)?.length === 2 ?
        nums
            .reduce((acc, curr, index) => curr === target / 2 ? [ ...acc, index ] : [ ...acc ], [] as number[])
        : nums
            .map((num) => (target % 2 === 1 || num !== target / 2) && numMap.has(target - num))
            .reduce((acc, curr, index) => curr === true ? [ ...acc, index ] : [ ...acc ], [] as number[]);
};

const getNumberMap = (nums: number[]): Map<number, number[]> => {
    const numMap = new Map<number, number[]>();
    nums.forEach((num, index) => numMap.get(num) ? numMap.get(num)?.push(index) : numMap.set(num, [index]));

    return numMap;
}
