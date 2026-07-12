class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        
        # strat: explore the stack dfs-like, looking for this condition:
        # 2 numbers and an op: specifically a num num op combo like that
        # must manage 'excess' correctly
        # does res of num num op get added 'in place' or to the top of stack?
        
        tokens.reverse()
        stack = tokens
        stop_condition = len(stack) == 1
        operators = ["+", "-", "*", "/"]
        while stop_condition is False:
            
            # each operation needs 2 numbers, so we assume
            # a) at least 2 numbers in the stack 
            # b) AND at least 1 operator in the stack
            
            excess = []         # how we store excess items from the stack
            c = [               # 3 candidates we consider for the operation, slides across stack
                stack.pop(), 
                stack.pop(), 
                stack.pop()
            ]
            
            print(f'Considering these candidates: {c}')

            found_op = (
                c[0] not in operators and
                c[1] not in operators and
                c[2] in operators
            )

            print(f'Is this operable? {found_op}')

            # this procedure searches for an operation to perform
            while found_op is False:
                # slide forward by 1 element, moving first of c into excess
                excess.append(c.pop(0))
                c.append(stack.pop())

                print(f'Considering these candidates: {c}')
                found_op = (
                    c[0] not in operators and
                    c[1] not in operators and
                    c[2] in operators
                )
                print(f'Is this operable? {found_op}')

            # this procedure computes the result;
            # important: which is num1 and num2?
            # c is top 3 stack elements: num1 is c[0], num2 is c[1], op is c[3]
            
            num1, num2, operator = int(c[0]), int(c[1]), c[2]
            match operator:
                case "+": res = num1 + num2
                case "-": res = num1 - num2
                case "*": res = num1 * num2
                case "/": res = int(num1 / num2)
            print(f'Result of previous operation: {res}')
            # we append the result in-place to the stack 
            stack.append(res)
            
            # we add the excess back to the stack such that it mimmics the original structure
            excess.reverse()
            stack = stack + excess
            
            print(f'Stack after operation result is added: {stack}')

            # we evaluate the stopping condition (only answer left in stack)
            stop_condition = len(stack) == 1

        # after every operation, we should have just 1 number left in the stack: the result
        ans = stack.pop()
        return int(ans)