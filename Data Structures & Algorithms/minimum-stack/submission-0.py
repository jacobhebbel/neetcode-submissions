class MinStack:

    def __init__(self):
        self.stack    = []
        self.minstack = []
    
    def push(self, val: int) -> None:
        
        has_elements = len(self.stack)
        if has_elements:
            self.stack.append(val)
            curr_min = self.minstack[-1]
            self.minstack.append(min(curr_min, val))
        else:
            self.stack.append(val)
            self.minstack.append(val)

    def pop(self) -> None:
        self.stack.pop()
        self.minstack.pop()

    def top(self) -> int:
        return self.stack[-1]

    def getMin(self) -> int:
        return self.minstack[-1]
