import torch
import torch.nn as nn
import torch.nn.functional as F

class AddNetwork(nn.Module):
    def __init__(self):
        super().__init__()
        self.nn = nn.Linear(2, 1)
        self.nn.weight = nn.Parameter(torch.tensor([[1.0, 1.0]]))  # Set weights
        self.nn.bias = nn.Parameter(torch.tensor([0.0]))           # Set bias
    def forward(self, x):
        x = self.nn(x)
        x = F.relu(x)
        return x

if __name__ == "__main__":
    a = 10.0
    b = 20.0
    model = AddNetwork()
    x = torch.tensor([a, b])
    s = model(x)
    print(s)