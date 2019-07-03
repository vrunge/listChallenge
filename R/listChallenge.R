
#' listChallenge
#' @description Challenge different singly linked lists written in C++ with a simplified structure. The only needed operations are : add element / delete element. Each element is made of two random unsigned integers obtained with the C rand function.
#' @param length number of element to add into the list
#' @param batch number of elements to add at each loop
#' @param prob probability of deleting an element. The list is scanned after each batch loop
#' @param method the method to use: std, vr1, vr2, al1, al2,...
#' @return a list with (i) the number of elements in the list after each loop (nb) and (ii) the overall system time in seconds (time)

listChallenge <- function(length, batch, prob, method = "std")
{
  ###############STOPS###############
  if(length%%1!=0 || length <= 0){stop('length is not a positive integer')}

  if(batch%%1!=0 || batch <= 0){stop('batch is not a positive integer')}
  if(batch > length){stop('batch is greater than length. We should have "batch <= length"')}

  if(prob >= 1 || prob < 0){stop('prob is not between 0 and 1 (0 <= prob < 1)')}

  if(method != "std" && method != "vr1" && method != "vr2" && method != "al1" && method != "al2")
    {stop('Argument "method" not appropriate. Choose among "std", "vr1", "vr2", "al1" or "al2')}

  ###get the number of loops
  nbLoops <- length%/%batch

  ###CALL Rcpp functions###
  start_time <- Sys.time()
  nb <- listChallenge_cpp(nbLoops, batch, prob, method)
  end_time <- Sys.time()
  time <- unclass(end_time - start_time)[1]

  #time in seconds
  response <- list(finalLength = nb, time = time)

  return(response)
}
