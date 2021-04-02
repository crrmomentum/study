import numpy as np
import json


def get_determinant(m):
    try:
        return np.linalg.det(m)
    except Exception as e:
        print(e)


def get_matrices(m, rows, cols):
    if rows == cols:
        det = round(get_determinant(m), 4)
        if det != 0:
            print(det)
            matrix_cofactor = np.matrix.round(np.dot(np.linalg.inv(m).T, det), 4)
            matrix_adj = matrix_cofactor.transpose()
            matrix_inv = np.matrix.round(np.linalg.inv(m), 4)
            result = {'TRANSPOSE': m.transpose().tolist(),
                      'COFACTOR': matrix_cofactor.tolist(),
                      'ADJ': matrix_adj.tolist(),
                      'INV': matrix_inv.tolist(),
                      'DET': det
                      }
        else:
            print("Determinant is zero or does not exist")
            result = {'TRANSPOSE': m.transpose().tolist(),
                      'COFACTOR': None,
                      'ADJ': None,
                      'INV': None,
                      'DET': 0
                      }
    else:
        print("Input matrices are not square, determinant doesn't exist")
        result = {'TRANSPOSE': m.transpose().tolist(),
                  'COFACTOR': None,
                  'ADJ': None,
                  'INV': None,
                  'DET': None
                  }
    return result


# Init dictionary
dictionary = {'input': {}}
dictionary['input']['A'] = {}
dictionary['input']['A']['1x1'] = {}
dictionary['input']['B'] = {}
dictionary['input']['B']['1x1'] = {}
dictionary['output'] = {}
dictionary['output']['SUM'] = {}
dictionary['output']['SUM']['1x1'] = {}

# Create a few random matrices of different sizes for testing
# Creating A and B random matrices
for i in range(1, 5):
    for j in range(1, 5):
        a = np.random.randint(20, size=(i, j))
        b = np.random.randint(20, size=(i, j))
        matrix_size = str(i) + 'x' + str(j)

        # A matrix
        temp_a = {'matrix': a.tolist(), 'rows': i, 'cols': j}
        dictionary['input']['A'][matrix_size] = temp_a
        dictionary['input']['A'][matrix_size]['ops'] = get_matrices(a, i, j)

        # B Matrix
        temp_b = {'matrix': b.tolist(), 'rows': i, 'cols': j}
        dictionary['input']['B'][matrix_size] = temp_b
        dictionary['input']['B'][matrix_size]['ops'] = get_matrices(b, i, j)

        # Perform +, -, *, / operations
        c = a + b
        temp_c = {'matrix': c.tolist(), 'rows': i, 'cols': j}
        dictionary['output']['SUM'][matrix_size] = temp_c
        dictionary['output']['SUM'][matrix_size]['ops'] = get_matrices(c, i, j)

# Printing final json
print(json.dumps(dictionary, indent=4))

# Open json file
with open('golden_matrices.json', 'w+') as json_file:
    json.dump(dictionary, json_file, indent=4)
