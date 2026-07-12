class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        
        
        stack = []
        operators = ["+", "-", "*", "/"]
        for tok in tokens:

            if tok not in operators: stack.append(tok)
            else:

                op = tok
                num2, num1 = int(stack.pop()), int(stack.pop())

                match op:
                    case "+": res = num1 + num2
                    case "-": res = num1 - num2
                    case "*": res = num1 * num2
                    case "/": res = int(num1 / num2)
        
                stack.append(res)
        
        # after every operation, we should have just 1 number left in the stack: the result
        ans = stack.pop()
        return int(ans)