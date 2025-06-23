# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: Optional[ListNode]
        :type l2: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        s1 = ''
        s2 = ''
        while l1:
            s1+= str(l1.val)
            l1 = l1.next
        
        while l2:
            s2+= str(l2.val)
            l2 = l2.next

        num = str(int(s1)+int(s2))
        dummy = ListNode(-1)
        temp = dummy
        for ch in num:
            temp.next = ListNode(int(ch))
            temp = temp.next
        
        return dummy.next
        