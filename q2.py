# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x, y = None):
        self.val = x
        self.next = y

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        arr1 = []
        while (l1.next != None) :
            arr1.append(l1.val)
            l1 = l1.next
        arr1.append(l1.val)
        
        arr2 = []
        while (l2.next != None) :
            arr2.append(l2.val)
            l2 = l2.next
        arr2.append(l2.val)
        
        if len(arr1) > len(arr2) :
            addzeros = len(arr1) - len(arr2)
            while addzeros > 0 :
                arr2.append(0)
                addzeros -= 1
                
        if len(arr1) < len(arr2) :
            addzeros = len(arr2) - len(arr1)
            while addzeros > 0 :
                arr1.append(0)
                addzeros -= 1
             
        assert len(arr1) == len(arr2), 'length is not the same'        
        arr3 = []
        presercve = 0
        for i in xrange(len(arr1)):
            tmp = arr1[i] + arr2[i] + presercve
            if tmp / 10 >= 1:
                presercve = tmp/10
                tmp = tmp%10
            else:
                presercve = 0
            arr3.append(tmp)
        
        if (presercve != 0):
            arr3.append(presercve)
        if sum(arr3) == 0:
            arr3 = [0]
        
        return arr3   
            
            
            
            
# better one
# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        dummy = ListNode(0)
        current = dummy
        sumx, carry = 0, 0
        while l1 or l2 :
            sumx = carry
            if l1:
                sumx += l1.val
                l1 = l1.next
            if l2:
                sumx += l2.val
                l2 = l2.next
            carry = sumx/10
            sumx = sumx%10
            current.next = ListNode(sumx)
            current = current.next
            
        if carry != 0:
            current.next = ListNode(carry)
        return dummy.next