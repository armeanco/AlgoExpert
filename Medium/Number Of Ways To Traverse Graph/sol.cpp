using namespace std;

int numberOfWaysToTraverseGraph(int width, int height) {
  int path = 1; 
  for (int i = width; i < (height + width - 1); i++) { 
    path *= i; 
    path /= (i - width + 1); 
  } 
  return path;
}
