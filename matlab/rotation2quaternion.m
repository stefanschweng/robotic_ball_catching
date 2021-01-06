% Author:
%  Mark Tincknell, MIT LL, 29 July 2011, revised 25 July 2017
function eout = rotation2quaternion( R )
  % function eout = RotMat2e( R )
  % One Rotation Matrix -> one quaternion
  eout = zeros( 4, 1 );
  if ~all( abs( R(:) ) <= eps(16) )
      eout(1) = 0.5 * sqrt( max( 0, 1 + R(1,1) + R(2,2) + R(3,3) ));
      if abs( eout(1) ) <= eps(16)
          if (R(1,1) > R(2,2)) && (R(1,1) > R(3,3))
              eout(2) = 0.5 * sqrt( 1 + R(1,1) - R(2,2) - R(3,3) );
              eout(1) = 0.25 *( R(3,2) - R(2,3) )/ eout(2);
              eout(3) = 0.25 *( R(1,2) + R(2,1) )/ eout(2); 
              eout(4) = 0.25 *( R(1,3) + R(3,1) )/ eout(2); 
          elseif R(2,2) > R(3,3)
              eout(3) = 0.5 * sqrt( 1 + R(2,2) - R(1,1) - R(3,3) );
              eout(1) = 0.25 *( R(1,3) - R(3,1) )/ eout(3);
              eout(2) = 0.25 *( R(1,2) + R(2,1) )/ eout(3); 
              eout(4) = 0.25 *( R(2,3) + R(3,2) )/ eout(3); 
          else
              eout(4) = 0.5 * sqrt( 1 + R(3,3) - R(1,1) - R(2,2) );
              eout(1) = 0.25 *( R(2,1) - R(1,2) )/ eout(4);
              eout(2) = 0.25 *( R(1,3) + R(3,1) )/ eout(4);
              eout(3) = 0.25 *( R(2,3) + R(3,2) )/ eout(4);
          end
      else
          eout(2) = 0.25 *( R(3,2) - R(2,3) )/ eout(1);
          eout(3) = 0.25 *( R(1,3) - R(3,1) )/ eout(1);
          eout(4) = 0.25 *( R(2,1) - R(1,2) )/ eout(1);
      end
  end
end % RotMat2e