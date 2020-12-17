package linkedList

//万物皆为空接口

type Object interface{}

type Node struct {
	Data Object
	Next *Node
}

type List struct{
	headNode *Node
}

//判空否
func (this *List) IsEmpty() bool {
	if this.headNode == nil{
		return true
	}else{
		return false
	}
}

//尾插
func (this *List) Append(data Object){
	node := &Node{Data: data}
	if this.IsEmpty() {
		this.headNode = node
	}else{
		cur := this.headNode
		for cur.Next != nil{
			cur = cur.Next
		}
		cur.Next = node
	}
}

//头插
func (this *List) Add(data Object) *Node{
	node := &Node{Data:data}
	node.Next = this.headNode
	this.headNode = node
	return node
}

//index插
func (this *List) Insert(index int,data Object){
	if index < 0 {
		this.Add(data)
	}else{
		pre := this.headNode
		count := 0
		for count <index -1 && pre.Next != nil{
			pre = pre.Next
			count++
		}
		node := &Node{Data:data}
		node.Next = pre.Next
		pre.Next = node
	}
}