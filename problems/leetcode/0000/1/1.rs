use std::collections::HashMap;

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut countMap: HashMap<i32, i32> = HashMap::new();
        let mut answer: Vec<i32> = vec![];

        for (index, num) in nums.iter().enumerate() {
            if countMap.contains_key(&(target - num)) {
                answer.push(*countMap.get(&(target - num)).unwrap());
                answer.push(index as i32);
                return answer;
            } else {
                countMap.insert(*num, index as i32);
            }
        }

        return answer;
    }
}
