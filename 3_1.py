import numpy as np


class Question1ofChap3:
    def __init__(self):
        self.array = np.arange(10)
        # where to start: 0, 4, 7 is the start of each array
        self.start_of_a = 0
        self.start_of_b = 4
        self.start_of_c = 7
        self.top_a = self.start_of_a
        self.top_b = self.start_of_b
        self.top_c = self.start_of_c

    def print_each_stack(self):
        print(self.array)
        print(self.array[self.start_of_a: self.start_of_b])
        print(self.array[self.start_of_b: self.start_of_c])
        print(self.array[self.start_of_c:])

    def push(self, where_to_push, what_to_push):
        if where_to_push is 'a' or 'A':
            if self.top_a == self.top_b:
                print("Stack a is full!")
            else:
                self.array[self.top_a] = what_to_push
                self.top_a = self.top_a + 1

        elif where_to_push is 'b' or 'B':
            if self.top_b == self.top_c:
                print("Stack b is full!")
            else:
                self.array[self.top_b] = what_to_push
                self.top_b = self.top_b + 1

        elif where_to_push is 'c' or 'C':
            if self.top_c == len(self.array)-1:
                print("Stack c is full!")
            else:
                self.array[self.top_c] = what_to_push
                self.top_c = self.top_c + 1

    # def pop(self, where_to_pop):


if __name__ == '__main__':
    question = Question1ofChap3()
    question.__init__()
    question.print_each_stack()
    question.push('a', 66)
    question.print_each_stack()
