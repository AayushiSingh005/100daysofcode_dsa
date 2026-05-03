def countSmaller(nums):
    n = len(nums)
    result = [0] * n
    indexed_nums = list(enumerate(nums))  # (index, value)

    def merge_sort(arr):
        if len(arr) <= 1:
            return arr

        mid = len(arr) // 2
        left = merge_sort(arr[:mid])
        right = merge_sort(arr[mid:])

        merged = []
        j = 0  # pointer for right array

        for i in range(len(left)):
            while j < len(right) and right[j][1] < left[i][1]:
                merged.append(right[j])
                j += 1
            result[left[i][0]] += j
            merged.append(left[i])

        merged.extend(right[j:])
        return merged

    merge_sort(indexed_nums)
    return result