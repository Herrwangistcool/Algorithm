import numpy
import os
import psutil
import gc
from memory_profiler import profile
import sys


def quick_sort(arr):
    """
    快速排序（二分法递归排序）
    原理：取数组第一个数作为标志，小于它的所有数放在一个列表，大于等于它的放在另一个列表，然后递归处理这两个数组。
        递归过程中会把列表越分越小，最小的列表中只包含一个数（二分法思想），小列表排好序后组合成一个列表即可。
    时间复杂度：O(nlogn)
    :param arr:
    :return:
    """
    if len(arr) > 1:
        left, right = [], []
        # 确定一个数，把所有小于它的数放在一个数组，把大于等于它的数放在一个数组
        for i in arr[1:]:
            if i < arr[0]:
                left.append(i)
            else:
                right.append(i)
        return quick_sort(left) + [arr[0]] + quick_sort(right) # 递归
    else:
        return arr


def select_sort(arr):
    """
    选择排序
    原理：选择一个最大的数，放在最后，在剩余的数中再选择一个最大的数，放在倒数第二个位置，
        如此反复，直到最后一个也被选择了出来，排序结束。
    时间复杂度：O(n^2)
    :param arr:
    :return:
    """
    size = len(arr)
    for i in range(size):
        # 寻找最小值
        min_value = arr[i]
        min_value_index = i
        for k in range(i, size):
            if arr[k] < min_value:
                min_value = arr[k]
                min_value_index = k
        # 交换
        arr[i], arr[min_value_index] = arr[min_value_index], arr[i]
    return arr

def bubble_sort(arr):
    """
    冒泡排序
    原理：从前向后，把相邻的两个数比较，如果前者大则交换，依次向后比较，一轮结束后，选出了最大值（在最后位置）。
        在剩余的数列中继续如此操作，这样每次都选出了剩余数中的最大值，供需进行n轮。
    时间复杂度：O(n^2)
    :param arr:
    :return:
    """
    size = len(arr)
    for i in range(size): # 共需进行n轮
        # 在剩余的数据中找出最大值，每一次外层循环都会使内容循环的次数减少1（因为每次找出一个较大值放在了后面）
        for k in range(size-i-1):
            if arr[k] > arr[k+1]:
                arr[k], arr[k+1] = arr[k+1], arr[k]
    return arr

#堆排序
def heap_sort(array):
    def heap_adjust(parent):
        child = 2 * parent + 1  # left child
        while child < len(heap):
            if child + 1 < len(heap):
                if heap[child + 1] > heap[child]:
                    child += 1  # right child
            if heap[parent] >= heap[child]:
                break
            heap[parent], heap[child] = \
                heap[child], heap[parent]
            parent, child = child, 2 * child + 1

    heap, array = array.copy(), []
    for i in range(len(heap) // 2, -1, -1):
        heap_adjust(i)
    while len(heap) != 0:
        heap[0], heap[-1] = heap[-1], heap[0]
        array.insert(0, heap.pop())
        heap_adjust(0)
    return array

#归并排序
def merge(a, b):
    c = []
    h = j = 0
    while j < len(a) and h < len(b):
        if a[j] < b[h]:
            c.append(a[j])
            j += 1
        else:
            c.append(b[h])
            h += 1
 
    if j == len(a):
        for i in b[h:]:
            c.append(i)
    else:
        for i in a[j:]:
            c.append(i)
 
    return c
 
@profile
def merge_sort(lists):
    if len(lists) <= 1:
        return lists
    middle = len(lists)//2
    left = merge_sort(lists[:middle])
    right = merge_sort(lists[middle:])
    return merge(left, right)


if __name__ == '__main__':


    maxSize = 1000

    for i in range(maxSize):
        array = list(numpy.random.randint(0, 100, 50))
    print('初始化数组:%.2f MB'%(psutil.Process(os.getpid()).memory_info().rss/1024/1024))
 

    for i in range(maxSize):
        array = list(numpy.random.randint(0, 100, 50))
    bubble_sort(array)
 

    for i in range(maxSize):
        array = list(numpy.random.randint(0, 100, 50))
    select_sort(array)
 

    for i in range(maxSize):
        array = list(numpy.random.randint(0, 100, 50))
    quick_sort(array)
    

    for i in range(maxSize):
        array = list(numpy.random.randint(0, 100, 50))
    heap_sort(array)


    for i in range(maxSize):
        array = list(numpy.random.randint(0, 100, 50))
    
    merge_sort(array)
    print('归并排序:%.2f MB'%(psutil.Process(os.getpid()).memory_info().rss/1024/1024))
