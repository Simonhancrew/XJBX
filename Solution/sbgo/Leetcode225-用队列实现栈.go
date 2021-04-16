package sbgo

type MyStack struct {
	queue1, queue2 []int
}

/** Initialize your data structure here. */
func Constructor() MyStack {
	return MyStack{}
}

/** Push element x onto stack. */
func (s *MyStack) Push(x int) {
	s.queue2 = append(s.queue2, x)
	for len(s.queue1) > 0 {
		s.queue2 = append(s.queue2, s.queue1[0])
		s.queue1 = s.queue1[1:]
	}
	s.queue1, s.queue2 = s.queue2, s.queue1
}

/** Removes the element on top of the stack and returns that element. */
func (s *MyStack) Pop() int {
	v := s.queue1[0]
	s.queue1 = s.queue1[1:]
	return v
}

/** Get the top element. */
func (s *MyStack) Top() int {
	return s.queue1[0]
}

/** Returns whether the stack is empty. */
func (s *MyStack) Empty() bool {
	return len(s.queue1) == 0
}
