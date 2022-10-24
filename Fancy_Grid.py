plus, minus, slash, height, width = input('Input 3 characters that will be used in the string separated by a space, then input the height and width separated by a space: ').strip().split()
height = int(height)
width = int(width)
def general_grid(plus,minus,slash,height,width):
    
    horizontal = 2*(plus+width*(' '+minus)+' ')+plus+'\n'
    gap = 2 * width + 1    
    vertical = height*(2*(slash+gap*(' '))+slash+'\n')
    
    print(horizontal + vertical + horizontal + vertical + horizontal)
    

general_grid(plus, minus, slash, height, width)
