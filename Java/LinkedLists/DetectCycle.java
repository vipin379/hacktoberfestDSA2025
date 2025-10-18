//Problem Statement:
// Given the head of a singly linked list, determine whether the linked list contains a cycle.
// A cycle exists if, by continuously following the next pointer, you can reach a node that you have already visited before.

//Floyd's Cycle Detection(Tortoise and Hare Algorithm):

// Use two pointers:
// slow → moves one step at a time
// fast → moves two steps at a time

// If there’s a cycle, both pointers will eventually meet inside the loop.
// If fast reaches null, the list ends — no cycle exists.

// Steps:

// 1.Initialize slow and fast to the head.

// 2.Move slow by one step and fast by two steps.

// 3.If they ever meet, a cycle exists.

// 4.If fast or fast.next becomes null, there’s no cycle.

// Time Complexity: O(n)
// Space Complexity: O(1)

import java.util.HashSet;

class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { 
        val = x; 
        next = null; 
    }
}

public class DetectCycle {
    public static boolean hasCycleFloyd(ListNode head) {
        if (head == null) return false;
        ListNode slow = head;
        ListNode fast = head;

        while (fast != null && fast.next != null) {
            slow = slow.next;          
            fast = fast.next.next;     
            if (slow == fast) {       
                return true;
            }
        }
        return false; // fast reached the end -> no cycle
    }

    public static ListNode createList(int[] vals, int pos) {
        if (vals == null || vals.length == 0) return null;
        ListNode head = new ListNode(vals[0]);
        ListNode tail = head;
        ListNode cycleNode = (pos == 0) ? head : null;

        for (int i = 1; i < vals.length; i++) {
            tail.next = new ListNode(vals[i]);
            tail = tail.next;
            if (i == pos) cycleNode = tail;
        }
        if (pos >= 0) {
            tail.next = cycleNode; 
        }
        return head;
    }

    public static void main(String[] args) {
        
        // Example: cycle at pos 1 (node with value 2)
        ListNode b = createList(new int[]{1,2,3,4,5}, 1);
        System.out.println("Floyd cycle:   " + hasCycleFloyd(b));      
       
    }
}