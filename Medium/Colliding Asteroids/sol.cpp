#include <vector>
std::vector<int> collidingAsteroids(std::vector<int> asteroids) {
  	int control = 6;
	while( control--> 0 ) {
      for( std::size_t i = 0; i < asteroids.size(); ++i ) {
        if( i + 1 < asteroids.size() && asteroids[i] > 0 && asteroids[i + 1] < 0 && asteroids[i] < asteroids[i + 1] *- 1 ) asteroids.erase(asteroids.begin() + i );	
		if( i + 1 < asteroids.size() && asteroids[i] > 0 && asteroids[i + 1] < 0 && asteroids[i] > asteroids[i + 1] *- 1 ) asteroids.erase(asteroids.begin() + i + 1 );
		if( i + 1 < asteroids.size() && asteroids[i] > 0 && asteroids[i + 1] < 0 && asteroids[i] == asteroids[i + 1] *- 1 ) {
			asteroids.erase( asteroids.begin() + i + 1 ), asteroids.erase( asteroids.begin() + i );
		}
      }
	}
	return {asteroids};
}
